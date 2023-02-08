use std::{io::Read, thread::panicking};

fn read_zero_what() {
    let mut buf = [0; 100];

    let A = std::io::stdin().read(&mut []).unwrap();
    println!("read {A}");

    let B = std::io::stdin().read(&mut buf).unwrap();
    println!("read {B} {buf:?}");
    println!("read {}", String::from_utf8(Vec::from_iter(buf)).unwrap());

}

fn pause() {
    println!("Press any key to continue...");
    if std::io::stdin().read_line(&mut String::new()).unwrap() == 0 {
        panic!("stdin closed");
    }
}

fn main() {
    read_zero_what();

    // loop {
    //     pause();
    //     println!("done");
    // }
}
