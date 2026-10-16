Create type account_type as enum('checking', 'savings', 'cd', 'money_market');

create table bank_accounts(
id serial primary key ,
account_type account_type,
balance integer
);

insert into bank_accounts(account_type,balance)
    values ('checking',1000),
        ('savings',2000),
        ('cd',3000),
        ('money_market',4000);


-- Do not modify below this line --
SELECT * FROM bank_accounts;
