from setuptools import find_packages, setup

package_name = "sensors"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="wesley",
    maintainer_email="wesleywong08@gmail.com",
    description="TODO: Package description",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "imu = sensors.sensor_publisher:imu_publisher",
            "depth = sensors.sensor_publisher:depth_publisher",
            "acoustic = sensors.sensor_publisher:acoustic_publisher",
        ],
    },
)
