#!/usr/bin/env python3
import sys
import subprocess
import systemd.daemon

proc = subprocess.Popen(
	'/usr/bin/fluidsynth -a jack -m alsa_seq --portname=fs -s -g 1 -o audio.jack.id=fs -L 28 -K 32 -f /root/fluidsynth/fs_load.txt --no-shell -s',
				shell=True,
				stdout=subprocess.PIPE)

for line in proc.stdout:
	print("Got line: %r" % line)
	if bytes("ID 28", "utf-8") in line:
		print("Telling systemd that deamon is ready")
		systemd.daemon.notify("READY=1")

proc.communicate()
code = proc.wait()
sys.exit(wait)
