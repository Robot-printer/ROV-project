import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ranger/ROV-project/ROV-project/Raspberry Pi/ros2-ws/install/ranger_auto'
