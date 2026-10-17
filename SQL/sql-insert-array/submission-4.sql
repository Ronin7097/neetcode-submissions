CREATE TABLE stocks (
  id serial PRIMARY KEY ,
  name TEXT,
  transaction_dates DATE[]
);

-- Do not modify above this line --

insert into stocks(name,transaction_dates)
  values ('AAPL',ARRAY['2007-02-09', '2007-02-10', '2007-02-11']::Date[]),
    ('GOOG',ARRAY['2004-12-15', '2004-12-16']::Date[]);
  

-- Do not modify below this line --
SELECT * FROM stocks;
