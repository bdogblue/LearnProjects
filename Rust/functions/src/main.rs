fn main() 
{
    println!("Hello, world!");

    some_other_function(34, 435);

    println!("The val of the fn _num is {}", _num());
}

fn some_other_function(x: i32, y: i32)
{
    println!("This is another function with {} and {}", x, y);
}

fn _num() -> i32
{
    45
}