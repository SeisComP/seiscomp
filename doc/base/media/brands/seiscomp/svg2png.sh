#!/bin/bash
# Converts SVG to PNG using inkscape. Note: The the -density option of
# ImageMagicks convert tool did not produced precise results.
for svg in *.svg; do
	echo
	echo "-----------------------------------------"
	echo "Converting $svg"
	echo
	basename="${svg:0:-4}"
	for res in 32 135 512; do
		inkscape -z -w ${res} -h ${res} -e "${basename}-${res}.png" "$svg"
	done
	inkscape -z -w 2134 -h 2134 -e "${basename}-hires.png" "$svg"
done
