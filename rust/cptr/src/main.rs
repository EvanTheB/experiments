use std::os::raw::c_void;

extern "C" {
    pub fn get_a_thing() -> *mut c_void;
    pub fn use_a_thing(p: *const c_void);
    pub fn mut_a_thing(p: *mut c_void);
    pub fn drop_a_thing(p: *mut c_void);
}

pub mod raw {
    use super::*;

    #[derive(Debug)]
    pub struct ThingMgr {
        thing: *mut c_void,
    }

    impl ThingMgr {
        pub fn new() -> ThingMgr {
            ThingMgr {
                thing: unsafe { get_a_thing() },
            }
        }
        pub fn use_a(&self) {
            unsafe { use_a_thing(self.thing) }
        }
        // BUG: doing a mutation without self being mut
        pub fn mut_a(&self) {
            unsafe { mut_a_thing(self.thing) }
        }
    }

    impl Drop for ThingMgr {
        fn drop(&mut self) {
            unsafe { drop_a_thing(self.thing) }
        }
    }
}

pub mod refs {
    use super::*;

    #[derive(Debug)]
    pub struct ThingMgr<'a> {
        thing: &'a mut c_void,
    }

    // BUG: The lifetime of is infectious
    pub struct ThingMgrMgr<'a>(ThingMgr<'a>);

    impl<'a> ThingMgr<'a> {
        pub fn new() -> ThingMgr<'a> {
            ThingMgr {
                thing: unsafe { &mut *get_a_thing() },
            }
        }
        pub fn use_a(&self) {
            unsafe { use_a_thing(self.thing) }
        }
        pub fn mut_a(&mut self) {
            unsafe { mut_a_thing(self.thing) }
        }
    }

    impl<'a> Drop for ThingMgr<'a> {
        fn drop(&mut self) {
            unsafe { drop_a_thing(self.thing) }
        }
    }
}

pub mod staticref {
    use super::*;

    #[derive(Debug)]
    pub struct ThingMgr {
        thing: &'static mut c_void,
    }

    impl ThingMgr {
        pub fn new() -> ThingMgr {
            // BUG: the lifetime is not really static
            // This might be fine? not clear from rust spec
            ThingMgr {
                thing: unsafe { &mut *get_a_thing() },
            }
        }
        pub fn use_a(&self) {
            unsafe { use_a_thing(self.thing) }
        }
        pub fn mut_a(&mut self) {
            unsafe { mut_a_thing(self.thing) }
        }
    }

    impl Drop for ThingMgr {
        fn drop(&mut self) {
            unsafe { drop_a_thing(self.thing) }
        }
    }
}

pub mod deref {
    use super::*;

    use std::ops::{Deref, DerefMut};

    #[derive(Debug)]
    pub struct ThingPtr {
        ptr: *mut c_void,
    }

    impl Deref for ThingPtr {
        type Target = c_void;

        fn deref(&self) -> &Self::Target {
            unsafe { self.ptr.as_ref() }.unwrap()
        }
    }

    impl DerefMut for ThingPtr {
        fn deref_mut(&mut self) -> &mut Self::Target {
            unsafe { &mut *self.ptr }
        }
    }

    #[derive(Debug)]
    pub struct ThingMgr {
        thing: ThingPtr,
    }

    impl ThingMgr {
        pub fn new() -> ThingMgr {
            ThingMgr {
                thing: ThingPtr {
                    ptr: unsafe { get_a_thing() },
                },
            }
        }
        pub fn use_a(&self) {
            // BUG: cant just do `&self.thing` : the coercion does not work?
            unsafe { use_a_thing(&*self.thing) }
        }
        pub fn mut_a(&mut self) {
            // can call the method instead
            unsafe { mut_a_thing(self.thing.deref_mut()) }
        }
    }

    impl Drop for ThingMgr {
        fn drop(&mut self) {
            unsafe { drop_a_thing(&mut *self.thing) }
        }
    }
}

pub mod asref {
    use super::*;


    #[derive(Debug)]
    pub struct ThingPtr {
        ptr: *mut c_void,
    }

    impl AsRef<c_void> for ThingPtr {
        fn as_ref(&self) -> &c_void {
            unsafe {&*self.ptr}
        }
    }

    impl AsMut<c_void> for ThingPtr {
        fn as_mut(&mut self) -> &mut c_void {
            unsafe { &mut *self.ptr }
        }
    }

    #[derive(Debug)]
    pub struct ThingMgr {
        thing: ThingPtr,
    }

    impl ThingMgr {
        pub fn new() -> ThingMgr {
            ThingMgr {
                thing: ThingPtr {
                    ptr: unsafe { get_a_thing() },
                },
            }
        }
        pub fn use_a(&self) {
            unsafe { use_a_thing(self.thing.as_ref()) }
        }
        pub fn mut_a(&mut self) {
            unsafe { mut_a_thing(self.thing.as_mut()) }
        }
    }

    impl Drop for ThingMgr {
        fn drop(&mut self) {
            unsafe { drop_a_thing(self.thing.as_mut()) }
        }
    }
}

fn main() {
    let t = raw::ThingMgr::new();
    println!("{t:?}");

    let t = refs::ThingMgr::new();
    println!("{t:?}");

    let t = staticref::ThingMgr::new();
    println!("{t:?}");

    let t = deref::ThingMgr::new();
    println!("{t:?}");

    let t = asref::ThingMgr::new();
    println!("{t:?}");
}
