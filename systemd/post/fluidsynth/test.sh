#!/bin/bash

mkfifo /tmp/waldo
systemd-notify --ready --status="Waiting for data..."

while : ; do
        read a < /tmp/waldo
        systemd-notify --status="Processing $a"

        # Do something with $a ...

        systemd-notify --status="Waiting for data..."
done
