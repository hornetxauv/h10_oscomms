from setuptools import find_packages
from setuptools import setup

setup(
    name='acoustic_msg',
    version='0.0.0',
    packages=find_packages(
        include=('acoustic_msg', 'acoustic_msg.*')),
)
