
// Convert temperatures between Fahrenheit and Celsius

use std::io;

fn main() 
{
    loop {
        let mut number = String::new();
        let mut answer = String::new();
        
        println!("Please enter whether you would like to convert from fahrenheit to celsius (1) or celsius to fahrenheit (2) or if you want to quit (3)");
        
        io::stdin()
            .read_line(&mut answer)
            .expect("Failed to read line");
        
        let answer: u32 = match answer.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        if answer == 1
        {
            println!("Enter fahrenheit: ");

            io::stdin()
                .read_line(&mut number)
                .expect("Failed to read line");
                
            let number: f32 = match number.trim().parse() {
                Ok(num) => num,
                Err(_) => continue,
            };
            
            println!("{} fahrenheit is {} in celsius", number, to_celsius(number));
        }
        else if answer == 2
        {
            println!("Enter celsius: ");
            
            io::stdin()
                .read_line(&mut number)
                .expect("Failed to read line");
                
            let number: f32 = match number.trim().parse() {
                Ok(num) => num,
                Err(_) => continue,
            };
            
            println!("{} celsius is {} in fahrenheit", number, to_fahren(number));
        }
        else if answer == 3
        {
            break;
        }
        else
        {
            println!("Please enter 1 or 2");
        }
    }
}

fn to_fahren(c: f32) -> f32
{
    c * (9.0/5.0) + 32.0
}

fn to_celsius(f: f32) -> f32
{
    (f - 32.0) * (5.0/9.0)
}