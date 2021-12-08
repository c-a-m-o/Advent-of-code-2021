use std::io::{BufRead, BufReader};

fn lines() -> impl Iterator<Item=String> {
    BufReader::new(std::io::stdin()).lines().map(Result::unwrap)
}

fn main() {
    let input : Vec<isize> = lines().map(|x|x.parse().unwrap()).collect();
    let res = input.windows(4).filter(|w|w[3]>w[0]).count();
    println!("{}", res);
}