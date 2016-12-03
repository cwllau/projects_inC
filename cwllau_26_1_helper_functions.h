float net_balance(float account_balance, float minimum_balance_fee);
float get_account_balance();
char get_account_type();
void get_account_holder(char account_holder[]);
int ask_to_exit();
void update_account_summary_information(int *total_number_of_accounts, float *total_amount_in_accounts, float account_balance);
void output_account_summary_to_file(int total_number_of_accounts, float total_amount_in_accounts, float total_minimum_balance_fees, int total_accounts_with_minimum_balance_fees);
void output_list_of_account_balances(float account_balances[], int number_of_accounts);

void print_summary_info(int total_number_of_accounts, float total_amount_in_accounts, float total_minimum_balance_fees, int total_accounts_with_minimum_balance_fees, float account_balances[], int number_of_accounts);