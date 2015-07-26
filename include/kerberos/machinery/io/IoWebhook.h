//
//  Class: IoWebhook
//  Description: A webhook class that posts to a specific URL.
//  Created:     25/07/2015
//  Author:      Cédric Verstraeten
//  Mail:        hello@cedric.ws
//  Website:     www.kerberos.io
//
//  The copyright to the computer program(s) herein
//  is the property of kerberos.io, Belgium.
//  The program(s) may be used and/or copied .
//
/////////////////////////////////////////////////////

#ifndef __IoWebhook_H_INCLUDED__   // if IoWebhook.h hasn't been included yet...
#define __IoWebhook_H_INCLUDED__   // #define this so the compiler knows it has been included

#include "machinery/io/Io.h"
#include "document.h"
#include "Writer.h"
#include "restclient-cpp/restclient.h"

namespace kerberos
{
    char WebhookName[] = "Webhook";
    class IoWebhook : public IoCreator<WebhookName, IoWebhook>
    {
        private:
            std::string m_url;
            std::string m_instanceName;

        public:
            IoWebhook(){};
            void setup(const StringMap & settings);
            
            void setUrl(std::string url){m_url=url;};
            const char * getUrl(){return m_url.c_str();};
            void setInstanceName(std::string instanceName){m_instanceName=instanceName;};
            std::string getInstanceName(){return m_instanceName;};
            
            bool save(Image & image){ return true; };
            bool save(Image & image, JSON & data);
    };
}
#endif