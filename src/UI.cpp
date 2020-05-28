#include "UI.hpp"

UI::Table::Table(size_t width_): fort::char_table(), width(width_) {
    set_border_style(FT_FRAME_STYLE);
};

template<typename T, typename ...Ts>
void UI::Table::addHeader(
    fort::text_style style,
    fort::text_align align,
    const T &str,
    const Ts &...strings
) {
    operator<<(fort::header);
    addRow(style, align, str, strings...);
};

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
};

template<typename T, typename ...Ts>
void UI::Table::addFullSizeHeader(
    fort::text_style style,
    fort::text_align align,
    const T &str,
    const Ts &...strings
) {
    currentCell().set_cell_span(width);
    addHeader(style, align, str, strings...);
};

void UI::Table::centerColumn(size_t id) {
    column(0).set_cell_text_align(fort::text_align::center);
};

void UI::Table::print() const {
    std::cout << to_string() << std::endl;
};

UI::HomeTable::HomeTable(const Rally& rally, int balance): Table(2) {
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
        "Name"
    );

    int index = 1;
    for (auto const &driver: rally.drivers) {
        addRow(
            fort::text_style::default_style,
            fort::text_align::left,
            std::to_string(index),
            driver.name
        );
        index++;
    }

    centerColumn(0);
    centerColumn(1);
};

UI::ResultsTable::ResultsTable(const Rally& rally, const Payoff& payoff): Table(3) {
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

    int position = 1;
    for (auto index: rally.getSortedResultsIndices()) {
        const DriverTime& result = rally.latestResults[index];

        addRow(
            fort::text_style::default_style,
            fort::text_align::left,
            "#" + std::to_string(position),
            result.driver.name,
            std::to_string(result.time.count())
        );
        position++;
    }

    addFullSizeHeader(
        fort::text_style::default_style,
        fort::text_align::center,
        "PAYOFF: " + std::to_string(payoff.value)
    );
};

UI::HomeScreen::HomeScreen(const Rally& rally, int balance):
    _balance(balance), _rally(rally), _table{rally, balance} {};

Bet UI::HomeScreen::display() const {
    Utils::clear();

    _table.print();
    std::cout << "MAKE A BET" << std::endl;
    auto driver = requestDriver();
    auto betAmount = Utils::request<int>("BET AMOUNT: ");

    return Bookmaker::makeBet(betAmount, driver);
};

Driver UI::HomeScreen::requestDriver() const {
    while (true) {
        auto driverNumber = Utils::request<int>("DRIVER NUMBER: ");

//        try {
            return _rally.getDriver(driverNumber);
//        } catch (const std::bad_optional_access &e) {
//            continue;
//        }
    }
};

UI::ResultsScreen::ResultsScreen(const Rally& rally, const Payoff& payoff):
    _rally(rally), _payoff(payoff), _table{rally, payoff} {};

void UI::ResultsScreen::display() const {
    Utils::clear();
    _table.print();
    Utils::pause();
};
