
// Generate the nth Fibonacci number

use std::io;

fn main() 
{
    loop
    {
        println!("Enter the nth Fibonacci number.");
        
        let mut last_num: u128;
        let mut curr_num: u128;
        let mut next_num: u128 = 0;

        let mut number = String::new();
    
        io::stdin()
          .read_line(&mut number)
          .expect("Failed to read line");

        let number: u32 = match number.trim().parse() {
            Ok(number) => number,
            Err(_) => continue,
        };
        
        println!();

        if number == 0
        {
            next_num = 0;
        }
        else if number == 1
        {
            next_num = 1;
        }
        else
        {
            
            last_num = 0;

            curr_num = 1;
            
            for num in 0..number
            {
                if num == 0
                {
                    next_num = 0;
                    
                    println!("{} -- {}", num+1, next_num);
                }
                else if num == 1
                {
                    next_num = 1;
                    
                    println!("{} -- {}", num+1, next_num);
                }
                else
                {
                    next_num = last_num + curr_num;
            
                    println!("{} -- {}", num+1, next_num);
                
                    last_num = curr_num;

                    curr_num = next_num;
                }
            }
        }
        
        println!();
        println!("The Fibonacci number is {}!", next_num);
        println!();
    }
}
