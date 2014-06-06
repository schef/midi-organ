#!/bin/bash
nc -w 10 127.0.0.1 8888 < $1
#cat $1 | netcat 127.0.0.1 8888
#netcat 127.0.0.1 8888 < $1
