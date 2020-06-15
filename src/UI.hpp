#pragma once
#include <iostream>
#include "Rally.hpp"
#include "Bookmaker.hpp"
#include "fort.hpp"

namespace UI {
    class Utils {
    public:
        // Request input from user with a message
        template<typename T>
        static T request(const std::string& message) {
            T value;
            while (std::cout << message && !(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            return value;
        }

        // Clear the screen
        static void clear() {
            #ifdef WINDOWS
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }

        // Pause the screen until some key is pressed
        static void pause() {
            #ifdef WINDOWS
                system("pause");
            #else
                system("read");
            #endif
        }

        // Format integer as a string with appropriate number of leading zeros
        static std::string toStringWithLeadingZeros(int value, int length) {
            auto toString = std::to_string(value);
            return std::string(length - toString.length(), '0') + toString;
        }

        // Format time: HH:MM:SS
        static std::string formatTime(int time) {
            int seconds = time;
            int minutes = seconds / 60;
            int hours = minutes / 60;

            return (
                "  " +
                UI::Utils::toStringWithLeadingZeros(hours, 2) +
                ":" +
                UI::Utils::toStringWithLeadingZeros(minutes % 60, 2) +
                ":" +
                UI::Utils::toStringWithLeadingZeros(seconds % 60, 2)
            );
        }

        // Format time with respect to a second one: +HH:MM:SS
        static std::string formatTime(int time, int reference) {
            int seconds = time - reference;
            int minutes = seconds / 60;
            int hours = minutes / 60;

            return (
                "+ " +
                UI::Utils::toStringWithLeadingZeros(hours, 2) +
                ":" +
                UI::Utils::toStringWithLeadingZeros(minutes % 60, 2) +
                ":" +
                UI::Utils::toStringWithLeadingZeros(seconds % 60, 2)
            );
        }
    };

    class TableStyles {
    public:
        typedef fort::text_style Appearance;
        Appearance appearance;

        typedef fort::text_align Alignment;
        Alignment alignment;

        typedef fort::color Color;
        Color textColor;
        Color backgroundColor;

        explicit TableStyles(Alignment alignment_);
        explicit TableStyles(Color textColor, Color backgroundColor_ = Color::black);
        explicit TableStyles(
            Appearance appearance_ = Appearance::default_style,
            Alignment _alignment_ = Alignment::left,
            Color textColor = Color::default_color,
            Color backgroundColor_ = Color::black
        );
    };

    class Table: public fort::char_table {
    public:
        explicit Table(size_t width_);

        template<typename T, typename ...Ts>
        void addHeader(
            const TableStyles& styles,
            const T &str,
            const Ts &...strings
        );

        template<typename T, typename ...Ts>
        void addRow(
            const TableStyles& styles,
            const T &str,
            const Ts &...strings
        );

        template<typename T, typename ...Ts>
        void addFullSizeHeader(
            const TableStyles& styles,
            const T &str,
            const Ts &...strings
        );

        void centerColumn(size_t id);
        void print() const;
    private:
        const size_t width;

        table_row currentRow() {
            return row(cur_row());
        }

        table_cell currentCell() {
            return cur_cell();
        }
    };

    class HomeTable : public Table {
    public:
        HomeTable(const Rally& rally, int balance);
    };

    class ResultsTable: public Table {
    public:
        ResultsTable(const Rally& rally, const Payoff& payoff);

    private:
        void addResult(const DriverTime& result, const Rally& rally, int pos, bool wasBet);
    };

    class HomeScreen {
    public:
        HomeScreen(const Rally& rally, int balance, const Bookmaker& bookmaker);
        Bet display() const;

    private:
        const Rally& _rally;
        const Bookmaker& _bookmaker;
        HomeTable _table;

        const Driver& requestDriver() const;
        int requestBetAmount() const;
    };

    class ResultsScreen {
    public:
        ResultsScreen(const Rally& rally, const Payoff& payoff);
        void display() const;

    private:
        ResultsTable _table;
    };
}
