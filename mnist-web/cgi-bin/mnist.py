#!/path/to/your/python/interpreter

"""
CGI script that accepts image urls and feeds them into a ML classifier. Results
are returned in JSON format.
"""

import io
import sys
import os
import re
import base64
import numpy as np
from PIL import Image
import uuid

import tensorflow as tf

# from model import model

# Default output
result = "null"
try:
    # Get post data
    if os.environ["REQUEST_METHOD"] == "POST":
        data = sys.stdin.read(int(os.environ["CONTENT_LENGTH"]))

        # Convert data url to numpy array
        img_str = re.search(r'base64,(.*)', data).group(1)
        image_bytes = io.BytesIO(base64.b64decode(img_str))
        im = Image.open(image_bytes)
        # Resize image to 28x28
        im = im.resize((28, 28))
        arr = np.array(im)[:, :, 0:1]

        # Normalize pixel values
        arr = (255 - arr)
        # np.savetxt("save-text/image_"+str(uuid.uuid1())+".txt", arr.reshape(784), fmt='%d')
        print(img_str, file=sys.stderr)
        arr2 = arr.reshape(784)
        arr3 = arr2.reshape(28, 28)
        arr4 = np.array([arr3 / 255.0])
        model = tf.keras.models.load_model("mnist.h5")
        predictions = model.predict(arr4)
        result = predictions[0]

except Exception as err:
    # Return error data
    print('ERROR:', err, file=sys.stderr)

# Print JSON response
print("Content-type: text/plain")
print("")
print(str(result))
