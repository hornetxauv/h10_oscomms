from setuptools import find_packages
from setuptools import setup

setup(
    name='linear_acceleration_msg',
    version='0.0.0',
    packages=find_packages(
        include=('linear_acceleration_msg', 'linear_acceleration_msg.*')),
)
