class SendRetryableCommand{
    public:
        SendRetryableCommand(const std::vector<smdb_type_filerid> &_nodes,
                bool (bcomka_lunImport_iterator::*op)(),
                refp<bcomka_lunImport_iterator> &itr):
                 _nodesList(_nodes),
                 _opToPerform(op),
                 _itr(itr)
          {
          }
        bool operator() (){
            BCOM_TRACE();
            bool result = false;
            std::vector<smdb_type_filerid>::iterator nodeItr;
            smdb_error err = smdb_error::InvalidOperation;
            //reverse the list to route the request to non-home node first.
            FIJI_EXEC_EXPR(fh_reversenoderetry, std::reverse(_nodesList.begin(),
                        _nodesList.end()));

            for (nodeItr =_nodesList.begin();nodeItr != _nodesList.end(); ++nodeItr) {
                _itr->clear_node();
                _itr->set_node(*nodeItr);
                BCOM_TRACE_DBG("Sending request to node: %s",
                        _itr->toString_node().c_str());
                if (!(*_itr.*_opToPerform)()){
                    BCOM_TRACE_ERR("BCOMKA returned failure error: %s: %u",
                            err.text().c_str(),err.get_value());
                    smdb_error err = _itr->getError();
                    // to set the return code to either retryrable or non retryable
                    smdb_error::code fiji_error_code = 0;
                    FIJI_SET_RETCODE_DEFVAL(fh_seterrorfromka, fiji_error_code,
                            smdb_error::NetworkError);
                    FIJI_EXEC_EXPR(fh_seterrorfromka, (err = fiji_error_code));

                    if (lunImportAction_iterator::isRetriable(err)) {
                        BCOM_TRACE_DBG("Retrying on error :%s:%u ",
                                err.text().c_str(),err.get_value());
                       // skip to next node, as received retryable error
                        continue;
                    } else {
                        // Error received was not retryable ,so break
                        result = false;
                        break;
                    }
                } else {
                    //Request successfully performed by BCOMKA , hence break
                    result = true;
                    break;
                }
            }

            BCOM_TRACE_DBG("BCOMKA  %d ",result);
            return result;
        }
    private:
        std::vector<smdb_type_filerid> _nodesList;
        bool (bcomka_lunImport_iterator::*_opToPerform)();
        refp<bcomka_lunImport_iterator> _itr;
};


