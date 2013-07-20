#include "Server.h"
#include "WebPage.h"
#include "Connection.h"

#include <QLocalServer>

Server::Server(QObject *parent) : QObject(parent) {
  m_server = new QLocalServer(this);
  m_page = new WebPage(this);
}

bool Server::start() {
  connect(m_server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
  return m_server->listen("capybara-webkit");
}

QString Server::server_name() {
  return m_server->fullServerName();
}

void Server::handleConnection() {
  QLocalSocket *socket = m_server->nextPendingConnection();
  new Connection(socket, m_page, this);
}
