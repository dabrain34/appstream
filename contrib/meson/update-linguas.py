#!/usr/bin/env python3
"""Regenerate the po/LINGUAS file from available .po files."""

import os
import sys

source_root = os.environ.get('MESON_SOURCE_ROOT', os.path.dirname(os.path.abspath(__file__)) + '/../..')
po_dir = os.path.join(source_root, 'po')

langs = sorted(
    os.path.splitext(f)[0]
    for f in os.listdir(po_dir)
    if f.endswith('.po')
)

with open(os.path.join(po_dir, 'LINGUAS'), 'w', newline='\n') as fh:
    for lang in langs:
        fh.write(lang + '\n')
