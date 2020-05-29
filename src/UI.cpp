#include "UI.hpp"

UI::Table::Table(size_t width_): fort::char_table(), width(width_) {
    set_border_style(FT_FRAME_STYLE);
}

template<typename T, typename ...Ts>
void UI::Table::addHeader(
    fort::text_style style,
    fort::text_align align,
    const T &str,
    const Ts &...strings
) {
    operator<<(fort::header);
    addRow(style, align, str, strings...);
}

template<typename T, typename ...Ts>
void UI::Table::addRow(
    fort::text_style style,
    fort::text_align align,
    const T &str,
    const Ts &...strings
) {
    currentRow().set_cell_text_style(style);
    currentRow().set_cell_text_align(align);
    write_ln(str, strings...);
}

template<typename T, typename ...Ts>
void UI::Table::addFullSizeHeader(
    fort::text_style style,
    fort::text_align align,
    const T &str,
    const Ts &...strings
) {
    currentCell().set_cell_span(width);
    addHeader(style, align, str, strings...);
}

void UI::Table::centerColumn(size_t id) {
    column(0).set_cell_text_align(fort::text_align::center);
}

void UI::Table::print() const {
    std::cout << to_string() << std::endl;
}

UI::HomeTable::HomeTable(const Rally& rally, int balance): Table(3) {
    addFullSizeHeader(
        fort::text_style::bold,
        fort::text_align::center,
        rally.name + "Betting Simulator"
    );
    addFullSizeHeader(
        fort::text_style::default_style,
        fort::text_align::left,
        "Balance: $" + std::to_string(balance)
    );
    addHeader(
        fort::text_style::default_style,
        fort::text_align::center,
        "Number",
        "Driver",
        "Wins"
    );

    for (auto index: rally.getDriversIndicesSortedByWins()) {
        auto driver = rally.drivers[index];
        addRow(
            fort::text_style::default_style,
            fort::text_align::left,
            std::to_string(index + 1),
            driver.name,
            std::to_string(driver.winsCount)
        );
    }

    centerColumn(0);
    centerColumn(1);
    centerColumn(2);
}

UI::ResultsTable::ResultsTable(const Rally& rally, const Payoff& payoff): Table(3), _rally(rally) {
    addFullSizeHeader(
        fort::text_style::bold,
        fort::text_align::center,
        "Latest Edition Results"
    );
    addHeader(
        fort::text_style::default_style,
        fort::text_align::center,
        "Rank",
        "Driver",
        "Time"
    );

    centerColumn(0);
    centerColumn(1);
    centerColumn(2);

    int iterator = 1;
    for (auto index: rally.getSortedResultsIndices()) {
        addResult(rally.latestResults[index], iterator);
        iterator++;
    }

    addFullSizeHeader(
        fort::text_style::default_style,
        fort::text_align::center,
        "PAYOFF: " + std::to_string(payoff.value)
    );
}

void UI::ResultsTable::addResult(const DriverTime& result, int pos) {
    auto bestResultIndex = _rally.getSortedResultsIndices()[0];
    auto position = "#" + std::to_string(pos);
    auto driverName = result.driver.name;
    auto time = (pos == 1) ? UI::Utils::formatTime(result.getTime()) :
        UI::Utils::formatTime(result.getTime(), _rally.latestResults[bestResultIndex].getTime());

    addRow(
        fort::text_style::default_style,
        fort::text_align::left,
        position,
        driverName,
        time
    );
};

UI::HomeScreen::HomeScreen(const Rally& rally, int balance, const Bookmaker& bookmaker):
    _balance(balance), _rally(rally), _bookmaker(bookmaker),  _table{rally, balance} {}

Bet UI::HomeScreen::display() const {
    Utils::clear();

    _table.print();
    std::cout << "MAKE A BET" << std::endl;
    auto driver = requestDriver();
    auto betAmount = Utils::request<int>("BET AMOUNT: ");
//
//    auto driver = Driver("XD");
//    auto betAmount = 12;

    return _bookmaker.makeBet(betAmount, driver);
}

Driver UI::HomeScreen::requestDriver() const {
    while (true) {
        auto driverNumber = Utils::request<int>("DRIVER NUMBER: ");

//        try {
            return _rally.getDriver(driverNumber);
//        } catch (const std::bad_optional_access &e) {
//            continue;
//        }
    }
}

UI::ResultsScreen::ResultsScreen(const Rally& rally, const Payoff& payoff):
    _rally(rally), _payoff(payoff), _table{rally, payoff} {};

void UI::ResultsScreen::display() const {
    Utils::clear();
    _table.print();
    Utils::pause();
}
