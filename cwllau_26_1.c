/*   File:  improved_min_bal_check.c
//   By:    The Awesome Students of EE160
//   Date:      Today :)
*/

#include <stdio.h>
#include "cwllau_26_1_macros.h"
#include "cwllau_26_1_helper_functions.h"
#include "cwllau_26_1_helper_functions.c"

// This program allows a teller to enter in account details and the program will calculate account information for the teller
int main() {
  float account_balance;
  char account_type;
  char exit_program_flag = CONTINUE_PROGRAM;
  int total_number_of_accounts = 0;
  float total_amount_in_accounts = 0;
  int minimum_balance_fee = 35;
  int total_minimum_balance_fees = 0;
  int total_accounts_with_minimum_balance_fees = 0;
  int minimum_balance_fee_charged_flag = 0;
  float account_balances[MAX_NUMBER_OF_ACCOUNTS];
  int current_account_number = 0;
  char account_holder[MAX_ACCOUNT_HOLDER_SIZE]; 
  char valid_account_type_flag = VALID_ACCOUNT_TYPE;
  
  while (exit_program_flag == CONTINUE_PROGRAM) {
    current_account_number++;
    minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_NOT_CHARGED;
    valid_account_type_flag = VALID_ACCOUNT_TYPE;
    get_account_holder(account_holder);
    account_balance = get_account_balance();
    account_type = get_account_type();
    
    if ((account_type == 's') && (account_balance < SAVINGS_ACCOUNT_MINIMUM_BALANCE)) {
      minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_CHARGED;
    } else if ((account_type == 'c') && (account_balance < CHECKING_ACCOUNT_MINIMUM_BALANCE)) {
      minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_CHARGED;
    } else {
      if ((account_type != 's') && (account_type != 'c')) {
        printf ("The account type was invalid\n");
        valid_account_type_flag = INVALID_ACCOUNT_TYPE;
      } else {
        printf ("A minimum balance fee does not need to be charged to this account\n");
      }
    }      
    
    if (valid_account_type_flag == VALID_ACCOUNT_TYPE) {
      // Display account summary information
      printf ("=== Account Information for %s's Account ===\n", account_holder);
      if (minimum_balance_fee_charged_flag) {
        total_accounts_with_minimum_balance_fees++;
        total_minimum_balance_fees += minimum_balance_fee;
        printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", minimum_balance_fee / account_balance * PERCENT_CONVERSION_FACTOR);
        printf ("The new account balance is %.2f\n", net_balance(account_balance, minimum_balance_fee));
      } else {
        printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", NO_MINIMUM_BALANCE / account_balance);
        printf ("The new account balance is $%.2f\n", net_balance(account_balance, NO_MINIMUM_BALANCE));
      }
      
      update_account_summary_information(&total_number_of_accounts, &total_amount_in_accounts, account_balance);
      account_balances[current_account_number+ARRAY_OFFSET] = account_balance;
    }
    
    exit_program_flag = ask_to_exit();
  }
  
  
  //FIX 26_1: Ask user how they want to see their summaries
  
  printf("Do you want to: \n");
  printf ("(enter f) to output to file\n");
  printf ("(enter s) to output to screen\n");
  printf ("(enter n) to output nothing\n");
  char summary_response;
  scanf ("\n%c", &summary_response);

if (summary_response =='f') {
  output_account_summary_to_file(total_number_of_accounts, total_amount_in_accounts, total_minimum_balance_fees, total_accounts_with_minimum_balance_fees);
  output_list_of_account_balances(account_balances, total_number_of_accounts);
}
if (summary_response =='s') {
print_summary_info(total_number_of_accounts, total_amount_in_accounts, total_minimum_balance_fees, total_accounts_with_minimum_balance_fees, account_balances, total_number_of_accounts);

}
  return 0;
}