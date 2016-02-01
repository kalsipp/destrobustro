#!/bin/bash

python img_conv_stolen.py left.jpg
for i in {0..17}
do
   echo "Welcome $i times"
   python img_conv_stolen.py path$i.jpg
done
