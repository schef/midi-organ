#!/usr/bin/env python3
import sys
import subprocess
import systemd.daemon

proc = subprocess.Popen(
	'/usr/bin/jackd -d alsa -d hw:0 -n 3 -r 44100 -p 128',
				shell=True,
				stdout=subprocess.PIPE)

for line in proc.stdout:
	print("Got line: %r" % line)
	if bytes("ALSA: use 3 periods for playback", "utf-8") in line:
		print("Telling systemd that deamon is ready")
		systemd.daemon.notify("READY=1")

proc.communicate()
code = proc.wait()
sys.exit(wait)
