-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';


SELECT interviews.name
FROM interviews
WHERE transcript LIKE '%bakery%'
AND month = 7
AND day = 28;


SELECT transcript
FROM interviews
WHERE transcript LIKE '%bakery%'
    AND month = 7
    AND day = 28;


SELECT name
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_location = 'Leggett Street'
    AND day = 28
    AND transaction_type = 'withdraw';


SELECT DISTINCT name
FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE phone_number IN
        (SELECT caller
         FROM phone_calls
         WHERE day = 28
             AND month = 7
             AND duration < 60);


SELECT id
FROM airports
WHERE city = 'Fiftyville';


SELECT flights.id
FROM flights
JOIN airports ON airports.id = origin_airport_id
WHERE airports.id = 8
    AND day = 29
    AND month = 7
ORDER BY hour,
         minute
 LIMIT 1;


SELECT name
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 36
AND name IN ('Bruce',
             'Diana',
             'Kenny',
             'Taylor',
             'Benista');


SELECT name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE name IN ('Bruce',
               'Kenny',
               'Taylor')
    AND day = 28
    AND month = 7
    AND hour = 10
    AND minute >= 15
    AND minute <= 30
    AND activity = 'exit';


SELECT city
FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.id = 36;


SELECT phone_number
FROM people
WHERE name = 'Bruce';


SELECT receiver
FROM phone_calls
WHERE caller = '(367) 555-5533'
    AND day = 28
    AND month = 7
    AND duration < 60;


SELECT name
FROM people
WHERE phone_number = '(375) 555-8161';


SELECT name
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 36
AND name = 'Robin';