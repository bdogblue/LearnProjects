
#[derive(Debug)]
struct Rectangle 
{
    width: u32,
    height: u32,
}

impl Rectangle
{
    fn area(&self) -> u32
    {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool 
    {
        self.width > other.width && self.height > other.height
    }

    fn square(size: u32) -> Rectangle
    {
        Rectangle
        {
            width: size,
            height: size,
        }
    }
}

fn main() 
{
    let rect1 = Rectangle 
    {
        width: 32,
        height: 64,
    };

    println!("The area of the rectangle is {} square pixels.", rect1.area());

    let rect2 = Rectangle {
        width: 30,
        height: 50,
    };
    let rect3 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect4 = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect2 hold rect3? {}", rect2.can_hold(&rect3));
    println!("Can rect2 hold rect4? {}", rect2.can_hold(&rect4));

    let sq = Rectangle::square(3);

    println!("sq is {:?}", sq);
}
