
# Chapter 9. Process Relationships


---

## 9-1

### Q. 

Refer back to our discussion of the `utmp` and `wtmp` files in Section 6.8. 
Why are the logout records written by the `init` process? 
Is this handled the same way for a network login?

### A. 

solution ref)
1. Terminal Login case
    `login` process doing login and, logout too.
    After logout, `login` process terminated, and `SIGCHLD` signal sent to `login` process' parent process: `init` process.
    Maybe there would be some situation that `login` process abnormally terminated(by some signals).
    So if `login` process writes the record of logout, it sometimes cannot do that when abnormal termination occurred.
    That's because `login` process does not write logout record: since it writes its own login record.
    Instead, `init` process do.

2. Network Login case
    `login` process' parent is not `init` this case.
    It would be a network login daemon: for the book's example, `telnetd`.
    So writing logout records is done by that process.

---

## 9-2

### Q. 

Write a small program that calls fork and has the child create a new session. 
Verify that the child becomes a process group leader and that the child no longer has a controlling terminal.

### A. 



---
