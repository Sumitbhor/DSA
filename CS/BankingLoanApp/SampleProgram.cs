public static class SampleProgram

{
    public static void RunSample()
    {

        var customerService = new CustomerService();
        var accountService = new AccountService();
        var productService = new LoanProductService();
        var creditService = new MockCreditCheckService();
        var notification = new ConsoleNotificationService(id => $"Customer:{id}");


        // seed product configs
        productService.Add(new LoanProduct { LoanType = LoanType.Personal, InterestRateAnnual = 12.0m, MaxAmount = 500000m, MinAmount = 10000m, MinCreditScore = 600, MaxTenureMonths = 60 });
        productService.Add(new LoanProduct { LoanType = LoanType.Home, InterestRateAnnual = 8.5m, MaxAmount = 10000000m, MinAmount = 500000m, MinCreditScore = 650, MaxTenureMonths = 360 });
        productService.Add(new LoanProduct { LoanType = LoanType.Auto, InterestRateAnnual = 10.0m, MaxAmount = 2000000m, MinAmount = 50000m, MinCreditScore = 620, MaxTenureMonths = 84 });

        // create customer and account
        var customer = new Customer { FullName = "Alice", DOB = new DateTime(1990, 1, 1), Email = "alice@example.com", Phone = "9999999999", Address = "Mumbai", PAN_SSN = "ABCDE1234F", AnnualIncome = 1200000m, CreditScore = 700 };
        customerService.Create(customer);

        var account = new Account { CustomerId = customer.CustomerId, AccountType = AccountType.Savings, Balance = 50000m };
        accountService.Create(account);

        // create application
        var appService = new LoanApplicationService(creditService, productService, notification);
        var application = new LoanApplication
        {
            CustomerId = customer.CustomerId,
            LoanType = LoanType.Personal,
            RequestedAmount = 200000m,
            RequestedTenureMonths = 36,
            ApplicantAnnualIncome = customer.AnnualIncome
        };

        appService.Create(application);
        appService.Submit(application.ApplicationId);
        appService.RunAutomatedChecks(application.ApplicationId);

        // officer review
        var officer = new SimpleLoanOfficer("Bob");
        var decision = officer.Review(application);
        Console.WriteLine($"Officer Decision: Approved={decision.Approved}, Notes={decision.Notes}");

        // loan service
        var loanService = new LoanService(productService, accountService, notification);
        if (decision.Approved)
        {
            var loan = loanService.ApproveAndCreateLoan(application, account.AccountId);
            application.Status = ApplicationStatus.Approved;
            application.ApprovedLoanId = loan.LoanId;
            loanService.Disburse(loan);


            // Show schedule summary
            Console.WriteLine($"Loan {loan.LoanId} Schedule: ");
            foreach (var ins in loan.Schedule.Take(3)) Console.WriteLine($"Inst{ins.Sequence}: Due {ins.DueDate:d} Amt {ins.Amount} P {ins.PrincipalComponent} I {ins.InterestComponent}");


            // Make a repayment
            Console.WriteLine("Making a repayment of 10000...");
            loanService.MakeRepayment(loan, 10000m, DateTime.UtcNow);
            Console.WriteLine($"Outstanding principal: {loan.OutstandingPrincipal:F2}");


            // Reporting
            var reporting = new ReportingService(loanService);
            reporting.PrintActiveLoans();
            reporting.PrintOverdueLoans();
            reporting.PrintPortfolioByType();
        }
        else
            {
                application.Status = ApplicationStatus.Rejected;
                notification.Notify(application.CustomerId, $"Your loan application was rejected: {decision.Notes}");
            }
    }         
}
