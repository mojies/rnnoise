#!/usr/bin/python
import os as os

singnalPath = '/share/tmp/singnal.pcm'
noisePath = '/share/tmp/noise.pcm'

singnalSize = os.path.getsize( singnalPath )

print( int( singnalSize/2/120 + 1 ) )

