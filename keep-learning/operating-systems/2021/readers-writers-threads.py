#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Description:  Readers writers problem
#               Two writers with precedence writing to a variable.
#               Three readers trying to read from the variable,
#               The readers get completely starved if not
#               implementing some kind of que system.
# Created by:   Nordin Suleimani
# Date:         2021-03-13
# Mod:          2021-03-13

from threading import Thread
from threading import Lock
from datetime import datetime

rdrThreadAmount, wrtrThreadAmount = 3, 2 #<------------ change amount of reader/writer threads as needed
shift, readerCount, writerCount, writing, reading, criticalVar = False, 0, 0, False, False, datetime.now().strftime("%Y-%m-%d %H:%M:%S::%f")

# locks
mutex = Lock()
mutex2 = Lock()

#Color codes, taken from web
class bcolors:
    CYAN    = '\033[96m'
    YELLOW  = '\033[93m'
    RED     = '\033[91m'
    ENDC    = '\033[0m'

class ReaderWriterThread(Thread):
    # constructor override
    def __init__(self, callerType):
        # calling parent class constructor
        Thread.__init__(self)
        self.isReader = callerType

    def run(self):
        while True:
            global criticalVar, readerCount, writerCount, writing, reading, shift
            mutex.acquire()
            #trap whoever enters here if a writer has already passed through
            while writerCount == 1:
                continue
            
            #trap the writer while readers are reading then
            #if the one passing is writer or reader, increment respectively
            if not self.isReader:
                while readerCount == 1:
                    continue
                writerCount += 1
            else:
                readerCount += 1

            mutex.release()
            mutex2.acquire()
            #As reader, print then decrement your count
            if self.isReader: 
                print(criticalVar + bcolors.CYAN + " -" + self.name + bcolors.ENDC)
                readerCount -= 1
            
            #As writer, write then decrement your count
            if not self.isReader:
                if shift:
                    criticalVar = bcolors.YELLOW + datetime.now().strftime("%Y-%m-%d %H:%M:%S::%f") + bcolors.ENDC
                    shift = False
                    print("----------------------------- New value, shifted: %s%s%s" %(bcolors.YELLOW, shift, bcolors.ENDC)) 
                else:
                    criticalVar = bcolors.RED + datetime.now().strftime("%f::%S:%M:%H %d-%m-%Y") + bcolors.ENDC
                    shift = True
                    print("----------------------------- New value, shifted: %s%s%s" %(bcolors.RED, shift, bcolors.ENDC)) 
                writerCount -= 1
            mutex2.release()

threads = []
def CreateThreads(ThreadRange: int, readerOrWriter: bool):
    for n in range(ThreadRange):
        t = ReaderWriterThread(readerOrWriter)
        t.start()
        threads.append(t)

# Create our readers and writers
CreateThreads(rdrThreadAmount, True)
CreateThreads(wrtrThreadAmount, False)

# ctrl-c ctrl-v :)
for t in threads:
   t.join()

###############################  LESSON LEARNED  #######################################