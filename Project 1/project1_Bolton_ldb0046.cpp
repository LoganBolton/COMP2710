//Logan Bolton - ldb0046
//project1_Bolton_ldb0046
//I used chatGPT to learn how to use "locale" settings to format 4 digit whole numbers.
//I also used chatGPT to figure out how to simplify my code using namespace std.
//Compile : g++ project1_Bolton_ldb0046.cpp
//Run : ./a.out

#include <iostream>
#include <locale>
using namespace std;

int main() {
    //declare input variables
    double totalBalance;
    double yearInterestRate;
    double monthlyPayment;

    cout << "Loan Amount: ";
    cin >> totalBalance;

    cout << "Interest Rate (% per year): ";
    cin >> yearInterestRate;
    yearInterestRate /= 100.0; // Convert percentage to decimal

    cout << "Monthly Payments: ";
    cin >> monthlyPayment;

    //declare variables used in data table
    bool isValidLoan = true;
    int months = 0;
    double monthlyInterestRate = yearInterestRate / 12;
    double payment;
    double principleBalance;
    double interestTotal;

    cout.imbue(locale("")); // Set the locale to the default locale, to use the thousands separator

    //formats the output of long decimal numbers
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

    if (yearInterestRate < 0 || totalBalance < 0 || monthlyPayment < 0) { //check for invalid negative numbers
        isValidLoan = false;
    }

    while (totalBalance > 0 && isValidLoan) {
        double interestBalance = totalBalance * monthlyInterestRate;

        if (interestBalance > monthlyPayment ) { //check for invalid state
            isValidLoan = false;
            break;
        }

        if (totalBalance > monthlyPayment) { //normal behavior
            payment = monthlyPayment;
            principleBalance = monthlyPayment - interestBalance;

            totalBalance -= principleBalance;
        } else { // if it is the final line
            payment = totalBalance + interestBalance;
            principleBalance = payment - interestBalance;

            totalBalance = 0;
        }

        //Prints line of data table
        cout << months << "\t$" << totalBalance;
        if (totalBalance < 1000) cout << "\t";
        cout << "\t$" << payment << "\t" << monthlyInterestRate * 100 << "\t$" << interestBalance << "\t\t$" << principleBalance << endl;
        
        months++;
        interestTotal += interestBalance;
    }

    //End of the data table
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