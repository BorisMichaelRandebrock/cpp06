
./Convert a       # Expected output:
                  # char: 'a'
                  # int: 97
                  # float: 97.0f
                  # double: 97.0

./Convert 42      # Expected output:
                  # char: '*'
                  # int: 42
                  # float: 42.0f
                  # double: 42.0

./Convert 128     # Expected output:
                  # char: Non displayable
                  # int: 128
                  # float: 128.0f
                  # double: 128.0

./Convert -42     # Expected output:
                  # char: Non displayable
                  # int: -42
                  # float: -42.0f
                  # double: -42.0

./Convert 2147483647 # Expected output:
                     # char: Non displayable
                     # int: 2147483647
                     # float: 2147483647.0f
                     # double: 2147483647.0

./Convert 3.14f   # Expected output:
                  # char: Non displayable
                  # int: 3
                  # float: 3.14f
                  # double: 3.14

./Convert 2.718   # Expected output:
                  # char: Non displayable
                  # int: 2
                  # float: 2.718f
                  # double: 2.718

./Convert nanf    # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: nanf
                  # double: nan

./Convert +inff   # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: +inff
                  # double: +inf

./Convert -inf    # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: -inf
                  # double: -inf

./Convert z       # Expected output:
                  # char: 'z'
                  # int: 122
                  # float: 122.0f
                  # double: 122.0

./Convert 0       # Expected output:
                  # char: Non displayable
                  # int: 0
                  # float: 0.0f
                  # double: 0.0

./Convert 7       # Expected output:
                  # char: Non displayable
                  # int: 7
                  # float: 7.0f
                  # double: 7.0

./Convert 340282346638528859811704183484516925440.0f # Expected output:
                                                    # char: imposible
                                                    # int: imposible
                                                    # float: +inf
                                                    # double: 3.402823466e+38

./Convert Hello   # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: imposible
                  # double: imposible

