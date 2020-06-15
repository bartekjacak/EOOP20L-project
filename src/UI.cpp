#include <cmath>
#include <algorithm>
#include "UI.hpp"

UI::Table::Table(size_t width_): fort::char_table(), width(width_) {
    set_border_style(FT_FRAME_STYLE);
}

template<typename T, typename ...Ts>
void UI::Table::addHeader(
    const TableStyles& styles,
    const T &str,
    const Ts &...strings
) {
    operator<<(fort::header);
    addRow(styles, str, strings...);
}

template<typename T, typename ...Ts>
void UI::Table::addRow(
    const TableStyles& styles,
    const T &str,
    const Ts &...strings
) {
    currentRow().set_cell_bg_color(styles.backgroundColor);
    currentRow().set_cell_content_fg_color(styles.textColor);
    currentRow().set_cell_text_style(styles.appearance);
    currentRow().set_cell_text_align(styles.alignment);
    write_ln(str, strings...);
}

template<typename T, typename ...Ts>
void UI::Table::addFullSizeHeader(
    const TableStyles& styles,
    const T &str,
    const Ts &...strings
) {
    currentCell().set_cell_span(width);
    addHeader(styles, str, strings...);
}

void UI::Table::centerColumn(size_t id) {
    column(id).set_cell_text_align(fort::text_align::center);
}

void UI::Table::print() const {
    std::cout << to_string() << std::endl;
}

UI::HomeTable::HomeTable(const Rally& rally, int balance): Table(3) {
    addFullSizeHeader(
        TableStyles(fort::text_style::bold, fort::text_align::center),
        rally.name + " Betting Simulator"
    );
    addFullSizeHeader(
        TableStyles(fort::text_align::left),
        "Balance: $" + std::to_string(balance)
    );
    addHeader(
        TableStyles(fort::text_align::center),
        "Number",
        "Driver",
        "Wins"
    );

    // Sort by wins
    int driversCount = rally.drivers.size();
    auto indices = std::vector<int>();
    indices.reserve(driversCount);
    for (int i = 0; i < driversCount; i++) indices.push_back(i);

    std::sort(indices.begin(), indices.end(), [rally](int lhs, int rhs) {
        return rally.drivers[lhs].winsCount > rally.drivers[rhs].winsCount;
    });

    for (auto index: indices) {
        auto driver = rally.drivers[index];
        addRow(
            TableStyles(fort::text_align::left),
            std::to_string(index + 1),
            driver.name,
            std::to_string(driver.winsCount)
        );
    }

    centerColumn(0);
    centerColumn(1);
    centerColumn(2);
}

UI::ResultsTable::ResultsTable(const Rally& rally, const Payoff& payoff): Table(3) {
    addFullSizeHeader(
        TableStyles(fort::text_style::bold, fort::text_align::center),
        "Latest Edition Results"
    );
    addHeader(
        TableStyles(fort::text_align::center),
        "Rank",
        "Driver",
        "Time"
    );

    centerColumn(0);
    centerColumn(1);
    centerColumn(2);

    int iterator = 1;
    for (auto index: rally.getSortedResultsIndices()) {
        auto wasBet = rally.latestResults[index].driver == payoff.bet.driver;
        addResult(rally.latestResults[index], rally, iterator, wasBet);
        iterator++;
    }

    auto isPayoffPositive = payoff.value >= 0;
    auto payoffColor = isPayoffPositive ? fort::color::green : fort::color::red;
    auto sign = isPayoffPositive ? std::string("+") : std::string("-");
    addFullSizeHeader(
        TableStyles(fort::text_style::default_style, fort::text_align::center, payoffColor),
        "PAYOFF: " + sign + "$" + std::to_string(abs(payoff.value))
    );
}

void UI::ResultsTable::addResult(const DriverTime& result, const Rally& rally, int pos, bool wasBet) {
    auto bestResultIndex = rally.getSortedResultsIndices()[0];
    auto position = "#" + std::to_string(pos);
    auto driverName = result.driver.name;
    auto time = (pos == 1) ? UI::Utils::formatTime(result.getTime()) :
        UI::Utils::formatTime(result.getTime(), rally.latestResults[bestResultIndex].getTime());

    auto color = wasBet ? fort::color::default_color : fort::color::dark_gray;

    addRow(
        TableStyles(fort::text_style::default_style, fort::text_align::left, color),
        position,
        driverName,
        time
    );
}

UI::TableStyles::TableStyles(Appearance appearance_, Alignment alignment_, Color color_, Color backgroundColor_):
    appearance(appearance_), alignment(alignment_), textColor(color_), backgroundColor(backgroundColor_) {}

UI::TableStyles::TableStyles(Alignment alignment_):
    appearance(Appearance::default_style), alignment(alignment_), textColor(Color::default_color), backgroundColor(Color::black) {}

UI::TableStyles::TableStyles(Color color_, Color backgroundColor_):
    appearance(Appearance::default_style), alignment(Alignment::left), textColor(color_), backgroundColor(backgroundColor_) {}

UI::HomeScreen::HomeScreen(const Rally& rally, int balance, const Bookmaker& bookmaker):
    _rally(rally), _bookmaker(bookmaker),  _table{rally, balance} {}

Bet UI::HomeScreen::display() const {
    Utils::clear();

    _table.print();
    std::cout << "MAKE A BET" << std::endl;
    const auto& driver = requestDriver();
    auto betAmount = requestBetAmount();

    return _bookmaker.makeBet(betAmount, driver);
}

const Driver& UI::HomeScreen::requestDriver() const {
    while (true) {
        auto driverNumber = Utils::request<int>("DRIVER NUMBER: ");

        try {
            return _rally.getDriver(driverNumber);
        } catch (const Rally::InvalidDriverIdError& error) {
            continue;
        }
    }
}

int UI::HomeScreen::requestBetAmount() const {
    while (true) {
        auto betAmount = Utils::request<int>("BET AMOUNT: ");

        if (betAmount > 0) {
            return betAmount;
        } else {
            continue;
        }
    }
}

UI::ResultsScreen::ResultsScreen(const Rally& rally, const Payoff& payoff): _table{rally, payoff} {}

void UI::ResultsScreen::display() const {
    Utils::clear();
    _table.print();
    Utils::pause();
}
