#!/usr/bin/env python3
import sys
import subprocess
import systemd.daemon

proc = subprocess.Popen(
	#'/root/midi-organ/systemd/boot/grandorgue/scripts/grandorgue.sh',
	'/usr/bin/GrandOrgue',
				shell=True,
				stdout=subprocess.PIPE)

for line in proc.stdout:
	print("Got line: %r" % line)
	if bytes("27)...OK\n", "utf-8") in line:
		print("Telling systemd that deamon is ready")
		systemd.daemon.notify("READY=1")

proc.communicate()
code = proc.wait()
sys.exit(wait)
