#!/usr/bin/env python
#-*- coding: utf-8 -*-
# Python 3.7

import subprocess
import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('path', type=str,  help='Path mini-solver executable')
    args = parser.parse_args()


    result = subprocess.run([args.path], capture_output=True)

    exit(0)
