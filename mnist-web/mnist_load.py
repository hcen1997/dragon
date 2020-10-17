import tensorflow as tf
import h5py
mnist = tf.keras.datasets.mnist

(x_train, y_train),(x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

model = tf.keras.models.load_model("mnist.h5")


test_loss, test_acc = model.evaluate(x_test, y_test)

print('\nTest accuracy:', test_acc)

model.summary()
# model.save('mnist.h5')
