#include <iostream>
#include <stack>
#include <vector>

class atm {
    std::stack<int> banknoteStack;
    const std::vector<int> bankNoteAvaliable = {200, 100, 50, 20, 10};

public:
    atm() {
        std::cout << "Automated Teller Machine initialized" << std::endl;
    }


    void withdrawBanknote(int value) {
        banknoteStack = std::stack<int>();
        int remaining = value;

        for (int bankNote : bankNoteAvaliable) {
            while (remaining >= bankNote) {
                banknoteStack.push(bankNote);
                remaining -= bankNote;
            }
        }
    }

    // Método para entregar as notas
    void deliverBankNote() {
        if (banknoteStack.empty()) {
            std::cout << "No banknotes to be delivered" << std::endl;
            return;
        }

        std::cout << "Banknotes to be delivered: $" << std::endl;
        while (!banknoteStack.empty()) {
            std::cout << banknoteStack.top() << "$ "  << std::endl;
            banknoteStack.pop();
        }
    }
};

int main() {
    atm* machine = new atm();

    int value;
    std::cout << "Type the amount of money to be withdraw:  $ ";
    std::cin >> value;

    machine->withdrawBanknote(value);
    machine->deliverBankNote();

    delete machine;

    return 0;
}
