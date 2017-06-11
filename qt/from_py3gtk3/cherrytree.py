#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#       cherrytree
#
#       Copyright 2009-2017 Giuseppe Penone <giuspen@gmail.com>
#
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 3 of the License, or
#       (at your option) any later version.
#
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#       MA 02110-1301, USA.

import os
import sys
import builtins
import argparse


def f_main(args):
    if hasattr(sys, 'frozen'):
        # windows, py2exe
        SHARE_PATH = os.path.dirname(sys.executable)
    else:
        SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
        if os.path.isfile(os.path.join(SCRIPT_DIR, 'glade', 'cherrytree.png'))\
        and os.path.isfile(os.path.join(SCRIPT_DIR, 'modules', 'main.py')):
            # not installed
            SHARE_PATH = SCRIPT_DIR
        else:
            # installed
            SHARE_PATH = os.path.join(os.path.dirname(SCRIPT_DIR), 'share')
            CHERRYTREE_PATH = os.path.join(SHARE_PATH, 'cherrytree')
            sys.path.insert(0, CHERRYTREE_PATH)
    builtins.SHARE_PATH = SHARE_PATH
    import modules.main
    modules.main.main(args)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs='?', help='Optional CherryTree Document to Open')
    parser.add_argument("-n", "--node", help="Node Name to Focus")
    parser.add_argument("-x", "--export_to_html_dir", help="Export to HTML at Specified Directory")
    parser.add_argument("-t", "--export_to_txt_dir", help="Export to Text at Specified Directory")
    parser.add_argument("-w", "--export_overwrite", action="store_true", help="Overwrite Existing Export")
    args = parser.parse_args()
    f_main(args)
