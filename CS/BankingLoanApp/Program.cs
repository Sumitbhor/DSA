//Main function code

Console.WriteLine("Running BankingLoanSystem sample...");
SampleProgram.RunSample();
Console.WriteLine("Sample run complete.");


/*
--->domain models (Customer, Account, LoanProduct, LoanApplication, Loan, Installment)
--->enums for statuses and loan/account types
--->interfaces ICreditCheckService and INotificationService (with mock/console implementations)
--->in-memory services for customers, accounts, loan products, applications, loans, and reporting
--->automated checks (amount limits, tenure limits, credit score, DTI check using applicant income)
--->officer review interface and simple implementation
--->EMI calculation + amortization schedule generator
---->disbursal, repayment handling (partial/full), schedule update logic
----->console notifications and simple sample Program demonstrating workflow (create customer, submit app, run checks, approve, disburse, repay, reports)
*/
