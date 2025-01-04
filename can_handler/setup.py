from setuptools import find_packages, setup

package_name = 'can_handler'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='CAN bus handler for SBC to receive and send messages from microcontrollers',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'can_handler = can_handler.can_handler:main',
                "fake_imu = can_handler.fake_sensors:imu_publisher"
        ],
    },
)
