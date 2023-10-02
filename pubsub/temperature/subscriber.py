import paho.mqtt.client as mosquitto

# https://pypi.org/project/paho-mqtt/

# callbacks
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected successfully")

def on_disconnect(client, userdata, rc):
    print("Disconnected successfully.")

def on_subscribe(client, userdata, flags, rc):
    print("Subscribed to the topic")

def on_message(client, userdata, msg):
    print("msg topic: " + str(msg.topic))
    print("msg payload: " + str(msg.payload))
    print("msg qos: " + str(msg.qos))
    print("--")

# creating a client
client = mosquitto.Client()

# setting callbacks
client.on_connect = on_connect
client.on_disconnect = on_disconnect
client.on_subscribe = on_subscribe
client.on_message = on_message

# connecting to the broker
client.connect(host="127.0.0.1", port=1883, keepalive=60, bind_address="")

# subscribing to the topic
client.subscribe(topic="sensors/temperature", qos=1)
# quality of service:
# 0: The broker/client will deliver the message once, 
#    with no confirmation.
# 1: The broker/client will deliver the message  at  
#    least  once,  with confirmation required.
# 2: The broker/client will deliver the message exactly 
#    once by using a four step handshake

# starting the looping thread
client.loop_forever()

# disconnecting
client.disconnect()

