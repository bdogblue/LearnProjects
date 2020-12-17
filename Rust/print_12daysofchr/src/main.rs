
// Print the lyrics to the Christmas carol “The Twelve Days of Christmas,” taking advantage of the repetition in the song.

fn main() 
{
    println!();
    println!("The Twelve Days of Christmas,");
    println!("--------------------------------");
    println!();
    
    for day in 0..12 
    {
        println!("On the {} day of Christmas, my true love sent to me", day_num(day));

        println!();

        let mut _lyrc = day;

        while _lyrc > 0
        {
            println!("{}", get_lyric(_lyrc));

            _lyrc -= 1;
        }
        
        if _lyrc == 0
        {
            println!("{}", get_lyric(_lyrc));
        }

        println!();
    }
}

fn day_num(num:usize) -> &'static str
{
    let days = ["first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"];

    return days[num];
}

fn get_lyric(num:usize) -> &'static str
{
    let _lyrics = ["A partridge in a pear tree", 
                "Two turtle doves, and", 
                "Three french hens", 
                "Four calling birds", 
                "Five golden rings", 
                "Six geese a-laying", 
                "Seven swans a-swimming", 
                "Eight maids a-milking", 
                "Nine ladies dancing", 
                "Ten lords a-leaping", 
                "Eleven pipers piping", 
                "Twelve drummers drumming"];

    return _lyrics[num];
}