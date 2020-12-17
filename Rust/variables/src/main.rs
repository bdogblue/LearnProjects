fn main()
{
    let x = 5;

    let x = x + 1;

    let x = x * 2;

    println!("The value of x is: {}", x);

    let spaces = "    ";
    let spaces = spaces.len();
    println!("This is the num of spaces {}", spaces);

    let trry: (f64, &str, u32) = (4.34, "hello there", 344);
    
    let (fl, fraze, num) = trry;

    println!("{}", fraze);
    println!("{}", num);
    println!("{}", fl);
}
