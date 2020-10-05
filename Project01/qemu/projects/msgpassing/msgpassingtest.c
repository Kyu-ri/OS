#include <stdio.h>

#include "projects/msgpassing/msgpassingtest.h"

void run_message_passing_test(void)
{
	printf("implement msgpassing and its tests !!!\n");

	controller();
}

void reader(int i) {

	message rmsg;
	while (ture) {
		rmsg = i;
		send(readrequest, rmsg);
		receive(mbox[i], rmsg);
		READUNIT();
		rmsg = i;
		send(finished, rmsg);
	}
}

void writer(int j) {

	message rmsg;
	while (ture) {
		rmsg = j;
		send(writerequest, rmsg);
		receive(mbox[j], rmsg);
		WRITEUNIT();
		rmsg = j;
		send(finished, rmsg);
	}
}
void controller() {

	while (true) {
		if (count > 0) {
			if (!empty(finished)) {
				receive(finished, msg);
				count++;
			}
			else if (!empty(writerequest)) {
				receive(writerequest, msg);
				writer_id = msg.id;
				count = count - 100;
			}
			else if (!empty(readrequest)) {
				receive(readrequest, msg);
				count--;
				send(msg.id, "OK");
			}
		}
		if (count == 0) {
			send(writer_id, "OK");
			receive(finished, msg);
			count = 100;
		}
		while (count < 0) {
			receive(finished, msg);
			count++;
		}
	}
}

