#!/usr/bin/env python3
import sys
import subprocess
import systemd.daemon

proc = subprocess.Popen(
	'/root/linuxsampler/linuxsampler.sh',
	#'/usr/bin/linuxsampler',
				shell=True,
				stdout=subprocess.PIPE)

for line in proc.stdout:
	print("Got line: %r" % line)
	#if bytes("26)...OK\n", "utf-8") in line:
	if bytes("27)...OK\n", "utf-8") in line:
		print("Telling systemd that deamon is ready")
		systemd.daemon.notify("READY=1")

proc.communicate()
code = proc.wait()
sys.exit(wait)
