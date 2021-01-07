class MessageParser(object):
    def __init__(self):
        pass
    
    # This function should return a list of dictionaries. Each element in the list represents a separate 
    # message that has been parsed. Each dictionary represents the different elements of that message:
    # the prefix, the command, and the list of params. An example of the data structure to be returned 
    # is shown below:
    # [message1, message2, message3], where
    # message1 =
    # {
    #   "prefix": "theshire.nz",
    #   "command": "SERVER",
    #   "params": ["rivendale.nz", 1, "Home of the Hobbits"]
    # }
    # message2 =
    # {
    #   "prefix": None,
    #   "command": "SERVER",
    #   "params": ["minastirith.nz", 1, "Tower of Guard"]
    # }
    # message3 =
    # {
    #   "prefix": None,
    #   "command": "QUIT",
    #   "params": None
    # }

    # When processing data received from a socket, it's possible that the data contains multiple commands
    # We need to split the message into a list of commands, which are delimited by \r\n
    def parse_data(self, recv_data):
        prefix = False
        T_param = False
        Message_List = []
        data = recv_data.decode()
        messages = data.split("\r\n")
        for i in messages:
            if i:
                prefix = False
                T_param = False
                if i.startswith(":"):
                    prefix = True
                #startswith() checks to see if a string starts with a specific character
                parsed_message = i.split(":")
                if len(parsed_message) == 3:
                    T_param = parsed_message[len(parsed_message)-1]
                if prefix:
                    parse_message_finish = parsed_message[1].split(" ")
                    #get prefix
                    if len(parse_message_finish) > 2:
                        params_Val = parse_message_finish[2:]
                        if len(parsed_message) == 3:
                            T_param = True
                    else:
                        params_Val = None
                    prefix_Val = parse_message_finish[0]
                    command_Val = parse_message_finish[1]
                else:
                    parse_message_finish = parsed_message[0].split(" ")
                    prefix_Val = None
                    command_Val = parse_message_finish[0]
                    if len(parsed_message) == 2:
                        T_param = True
                    if len(parse_message_finish) == 1:
                        params_Val = None
                    else:
                        params_Val = parse_message_finish[1:]
                if params_Val != None:
                    if params_Val[len(params_Val)-1] == "":
                        params_Val.remove("")

                if T_param:
                    if params_Val == None:
                        params_Val = parsed_message[len(parsed_message)-1]
                    else:
                        params_Val.append(parsed_message[len(parsed_message)-1])
                diction = {"prefix": prefix_Val, "command": command_Val, "params": params_Val}
                Message_List.append(diction)
        return Message_List