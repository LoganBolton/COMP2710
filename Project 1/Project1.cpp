#include <iostream>
#include <locale>
using namespace std;

int main() {

    double totalBalance;
    double yearInterestRate;
    double monthlyPayment;
    bool isValidLoan = true;

    cout << "Loan Amount: ";
    cin >> totalBalance;

    cout << "Interest Rate (% per year): ";
    cin >> yearInterestRate;
    yearInterestRate /= 100.0; // Convert percentage to decimal

    cout << "Monthly Payments: ";
    cin >> monthlyPayment;

    int months = 0;
    double monthlyInterestRate = yearInterestRate / 12;

    double payment;
    double principleBalance;
    double interestTotal;

    cout.imbue(locale("")); // Set the locale to the default locale, to use the thousands separator

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\n*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    //Header before first payment
    cout << months++ << "\t$" << totalBalance;
    if (totalBalance < 1000 && totalBalance > 0) cout << "\t";
    cout << "\tN/A\tN/A\tN/A\t\tN/A\n";

    if (yearInterestRate < 0 || totalBalance < 0 || monthlyPayment < 0) { //check for invalid state with negative numbers
        isValidLoan = false;
    }

    while (totalBalance > 0 && isValidLoan) {
        double interestBalance = totalBalance * monthlyInterestRate;


        if (interestBalance > monthlyPayment ) { //check for invalid state
            isValidLoan = false;
            break;
        }

        if (totalBalance > monthlyPayment) { //normal
            payment = monthlyPayment;
            principleBalance = monthlyPayment - interestBalance;
        } else {
            payment = totalBalance + interestBalance;
            principleBalance = payment - interestBalance;
        }

        if (totalBalance > monthlyPayment) { //normal
            totalBalance -= principleBalance;
        } else {
            totalBalance = 0;
        }

        cout << months << "\t$" << totalBalance;
        if (totalBalance < 1000) cout << "\t";
        cout << "\t$" << payment << "\t" << monthlyInterestRate * 100 << "\t$" << interestBalance << "\t\t$" << principleBalance << endl;
        
        months++;
        interestTotal += interestBalance;
    }

    cout << "*****************************************************************\n" << endl;
    if (isValidLoan) {
        cout << "It takes " << --months << " months to pay off the loan." << endl;
        cout.imbue(locale("")); // Set the locale to the default locale, which will use the appropriate thousands separator
        cout << "Total interest paid is: $" << interestTotal << endl << endl;
        return 0;
    }
    else {
        cout << "Error: Invalid Loan" << endl << endl;
    }
}
