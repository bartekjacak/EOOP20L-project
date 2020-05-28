#pragma once
#include <iostream>
#include "Rally.hpp"
#include "Bookmaker.hpp"
#include "fort.hpp"

namespace UI {
    class Utils {
    public:
        template<typename T>
        static T request(const std::string& message) {
            T value;
            while (std::cout << message && !(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            return value;
        }

        static void clear() {
            #ifdef WINDOWS
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }

        static void pause() {
            #ifdef WINDOWS
                system("pause");
            #else
                system("read");
            #endif
        }
    };

    class Table: public fort::char_table {
    public:
        explicit Table(size_t width_);

        template<typename T, typename ...Ts>
        void addHeader(
            fort::text_style style,
            fort::text_align align,
            const T &str,
            const Ts &...strings
        );

        template<typename T, typename ...Ts>
        void addRow(
            fort::text_style style,
            fort::text_align align,
            const T &str,
            const Ts &...strings
        );

        template<typename T, typename ...Ts>
        void addFullSizeHeader(
            fort::text_style style,
            fort::text_align align,
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
        ResultsTable(const RallyEdition& edition, const Payoff& payoff);
    };

    class HomeScreen {
    public:
        HomeScreen(const Rally& rally_, int balance_);
        Bet display() const;

    private:
        int _balance;
        const Rally& _rally;
        HomeTable _table;

        Driver requestDriver() const;
    };

    class ResultsScreen {
    public:
        const RallyEdition& _edition;
        const Payoff& _payoff;
        ResultsTable _table;

        ResultsScreen(const RallyEdition& edition_, const Payoff& payoff_);
        void display() const;
    };
};
