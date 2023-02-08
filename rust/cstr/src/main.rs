use std::{ffi::CString, ptr::null, os::raw::c_char};
fn main() {
    let s = Some(CString::new("abc").unwrap());

    // y outlives the cstring
    let y: *const c_char = s.clone().map_or(null(), |x| x.as_ptr());

    // thought this would work but it doesnt, I guess it does take ownership
    let y: *const c_char = s.clone().map_or(null(), |ref x| x.as_ptr());

    // seems wrong, deref should give *c_char but it gives &CStr
    // soln: its because deref gives Cstr which then has as_ptr
    // let y: *const c_char = s.clone().as_deref().or(null());

    // manually use the deref, but this is wrong because it outlives the CString
    let y: *const c_char = (*(s.clone().unwrap())).as_ptr();

    // seems to work
    let y: *const c_char = s.as_ref().map_or(null(), |x| x.as_ptr());
    let y: *const c_char = s.as_deref().map_or(null(), |x| x.as_ptr());

    println!("{:?}", s);
}
