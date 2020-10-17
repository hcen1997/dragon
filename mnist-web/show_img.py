#!/usr/bin/python3

# Simple script to show a picture of the captured image
# Script assumes image.txt is present in the current directory
# Requires numpy and matplotlib

import numpy as np
import matplotlib.pyplot as plt
import sys
import tensorflow as tf
mnist = tf.keras.datasets.mnist

(x_train, y_train),(x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

arr = np.loadtxt("save-text/image_a6735b40-e6b4-11e9-afa7-acb57dc18783.txt")
arr2 = arr.reshape(28, 28)
# plt.imshow(arr2)

model = tf.keras.models.load_model("mnist_save")

x1 = x_test[0]
p1 = model.predict(np.array([x_test[0]]))
p2 = model.predict(np.array([arr2/255.0]))

print(p1)
print(p2)