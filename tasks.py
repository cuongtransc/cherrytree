#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import logging
from datetime import datetime

from fabric import Connection
from invoke import task


FORMATTER = logging.Formatter(
    '%(asctime)s - %(levelname)s - %(message)s')

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

console_handler = logging.StreamHandler()
console_handler.setFormatter(FORMATTER)
logger.addHandler(console_handler)


##############################################################
# Dev
##############################################################

@task
def install(c):
    c.run('sudo pip install -r requirements.txt')
    c.run('sudo python setup.py install')

