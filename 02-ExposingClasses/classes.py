#!/usr/bin/env python

import classes
import time

t = classes.World()
msg = t.many(['Good Morning', 'Buon giorno', 'Kali mera'])
print(msg)
print(t.greet())
print("Start : %s" % time.ctime())
time.sleep(5)
print("End : %s" % time.ctime())
t.set("bom dia!")
print (t.greet())
print('---------------Done---------------')


