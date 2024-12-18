import time

import paho.mqtt.client as mqtt

# https://pypi.org/project/paho-mqtt/


# callbacks
def on_connect(client, userdata, flags, rc, properties):
    if rc == 0:
        print("Connected")


def on_disconnect(client, userdata, flags, rc, properties):
    print("Disconnected successfully.")


def on_publish(client, userdata, mid, reason_code, properties):
    print("Message ", str(mid), " published.")


# creating a client
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

# setting callbacks
client.on_connect = on_connect
client.on_disconnect = on_disconnect
client.on_publish = on_publish

# connecting to the broker
# connect(host, port=1883, keepalive=60, bind_address="")
client.connect(host="127.0.0.1", port=1883)

# starting the looping thread
# client.loop_start()

# publishing to the topic
client.publish(topic="sensors/temperature", payload="50", qos=0,
               retain=False)

# NOTE: publish an empty payload to clear retained messages
# client.publish(topic="sensors/temperature", payload="", qos=0, retain=True)

# disconnecting
client.disconnect()

# stoping the looping thread
client.loop_stop()
